from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import sys
import math
import numpy as np

# ---------------------- IZOMETRIJE ----------------------------------

def Euler2A(phi, theta, psi):

    R_z = np.array([[math.cos(psi), -math.sin(psi), 0],
                    [math.sin(psi), math.cos(psi), 0],
                    [0, 0, 1]])

    R_y = np.array([[math.cos(theta), 0, math.sin(theta)],
                    [0, 1, 0],
                    [-math.sin(theta), 0, math.cos(theta)]])

    R_x = np.array([[1, 0, 0],
                    [0, math.cos(phi), -math.sin(phi)],
                    [0, math.sin(phi), math.cos(phi)]])

    A = (R_z.dot(R_y)).dot(R_x)
    return A

def crossProduct(r, q):
    p = np.zeros((1, 3))
        
    p[0][0] = r[1]*q[2] - r[2]*q[1]
    p[0][1] = r[2]*q[0] - r[0]*q[2]
    p[0][2] = r[0]*q[1] - r[1]*q[0]

    return p

def dotProduct(r, q):
    return r[0]*q[0] + r[1]*q[1] + r[2]*q[2]

def AxisAngle(A):

    # Provera da li je matrica A matrica rotacije
    cond1 = A.dot(A.T).round(5) == np.eye(3)
    cond1 = cond1.all()
    cond2 = np.linalg.det(A).round(3) == 1.0    
    if not cond1 or not cond2:
        print("Matrica A nije matrica kretanja")
        return -1, -1

    X = A - np.eye(3)

    r = np.array([X[0][0], X[0][1], X[0][2]])
    q = np.array([X[1][0], X[1][1], X[1][2]])

    p = crossProduct(r, q)
    # ako su r i q linearno zavisni
    if p[0][0] == 0 and p[0][1] == 0 and p[0][2] == 0: 
        q = np.array([X[2][0], X[2][1], X[2][2]])

    norm_p = math.sqrt(p[0][0]**2 + p[0][1]**2 + p[0][2]**2)
    p = p * (1/norm_p) # jedinicni vektor

    norm_r = math.sqrt(r[0]**2 + r[1]**2 + r[2]**2)
    u = r * (1/norm_r) 

    u_prim = A.dot(u)

    cos_phi = dotProduct(u, u_prim)
    phi = math.acos(cos_phi)

    return p, phi

def AxisAngle2Q(p, phi):

    # Provera da li je vektor p jedinicni
    norm = math.sqrt(p[0][0]**2+p[0][1]**2+p[0][2]**2)
    p = p * (1/norm) # normalizacija

    w = math.cos(phi/2)

    r = math.sin(phi/2) * p

    q = np.array([r, w])

    # sredjivanje kvaterniona (za lakse indeksiranje kasnije)
    q = np.array([q[0][0][0], q[0][0][1], q[0][0][2], q[1]])

    return q

def Q2AxisAngle(q):

    # Provera da li je kvaternion jedinicni
    norm = math.sqrt(q[0]**2+q[1]**2+q[2]**2+q[3]**2)
    q = q * (1/norm) # normalizacija

    w = q[3]

    if w < 0:
        q = -q

    phi = 2*math.acos(w)

    if abs(w) == 1:
        p = np.array([1, 0, 0])
    else:
        v = np.array([q[0], q[1], q[2]])
        norm_v = math.sqrt(v[0]**2 + v[1]**2 + v[2]**2)
        p = v * (1/norm_v)

    return p, phi

def slerp(q1, q2, tm, t):

	tmp = np.clip(t, 0, 1)

	# Provera da li su q1 i q2 jedinicni
	norm = math.sqrt(q1[0]**2+q1[1]**2+q1[2]**2+q1[3]**2)
	q1 = q1 * (1/norm)
	norm = math.sqrt(q2[0]**2+q2[1]**2+q2[2]**2+q2[3]**2)
	q2 = q2 * (1/norm)
	cosO = np.dot(q1, q2)    
	
	if cosO < 0: # kraci luk sfere
	    q1 = -q1
	    cosO = -cosO
	if cosO > 0.95: # kvaternioni su blizu
	  	qs = q1*(1-t) + q2*t
	  	norm = math.sqrt(qs[0]**2+qs[1]**2+qs[2]**2+qs[3]**2)
	  	qs = qs * (1/norm)
	  	return qs
	
	phi_0 = math.acos(cosO)
	
	qs_1 = (math.sin(phi_0*(1-t/tm))) / (math.sin(phi_0)) * q1
	qs_2 = (math.sin(phi_0*(t/tm))) / (math.sin(phi_0)) * q2
	qs = qs_1 + qs_2
	
	return qs

# ------------------------------------------------------------------    

begin = [-2, -2, -2]
end = [4, 5, 7] 

beginAngles = [-math.pi/3, math.pi/2, math.pi/4]
endAngles = [math.pi/3, -math.pi/4, math.pi/5]

q = []
q1 = []
q2 = []

t = 0
tm = 100

TIMER_ID = 0
TIMER_INTERVAL = 25

animation_ongoing = False


def keyboard(key, x, y):
    
    global animation_ongoing
            
    # pokretanje animacije na taster S
    if ord(key) == ord('S'):
        if not animation_ongoing:
            glutTimerFunc(TIMER_INTERVAL, timer, TIMER_ID)
            animation_ongoing = True
        animation_ongoing = True
                
            
def timer(value):

    if value != TIMER_ID:
        return
    
    global t
    global animation_ongoing

    t += 0.5
        
    if t > tm:
        t = 0
        animation_ongoing = False
        return
    
    glutPostRedisplay()
    
    if animation_ongoing:
        glutTimerFunc(TIMER_INTERVAL, timer, TIMER_ID)


def display():
        
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    
    # Postavljanje pogleda    
    glViewport(0, 0, 600, 600)
    
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    gluPerspective(60, float(600)/ 600, 2, 25)
    
    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()
    gluLookAt(-15, -10, 10, 0, 0, 0, 0, 1, 0)
    
    # Pocetni polozaj
    drawAxis(begin, beginAngles)
    # Krajnji polozaj
    drawAxis(end, endAngles) 
    
    animate()
    
    glutSwapBuffers()
        

def animate():
    
    glPushMatrix()
    glColor3f(0.2, 0.2, 0.2)
    
    # Trenutni polozaj
    currPos = []
    
    currPos.append((1 - t/tm)*begin[0] + (t/tm)*end[0])
    currPos.append((1 - t/tm)*begin[1] + (t/tm)*end[1])
    currPos.append((1 - t/tm)*begin[2] + (t/tm)*end[2])

    glTranslatef(currPos[0], currPos[1], currPos[2])
    
    # ------------------------------------------

    q = slerp(q1, q2, tm, t)    
    p, phi = Q2AxisAngle(q)

    # ------------------------------------------
    
    glRotatef(phi / math.pi*180, p[0], p[1], p[2])
    
    # Iscrtavanje koordinata
    glBegin(GL_LINES)
    
    # x koordinata
    glColor3f(1, 0, 0)
    glVertex3f(0, 0, 0)
    glVertex3f(4, 0, 0)
        
    # y koordinata
    glColor3f(0, 1, 0)
    glVertex3f(0, 0, 0)
    glVertex3f(0, 4, 0)
        
    # z koordinata   
    glColor3f(0, 0, 1)
    glVertex3f(0, 0, 0)
    glVertex3f(0, 0, 4)
    
    glEnd()
    
    glPopMatrix()
    

def drawAxis(pos, currAngles):
    glPushMatrix()
    
    glColor3f(0.2, 0.2, 0.2)
    
    glTranslatef(pos[0], pos[1], pos[2])

    # ---------------------------------------
    
    A = Euler2A(currAngles[0], currAngles[1], currAngles[2])
    p, phi = AxisAngle(A)

    # ---------------------------------------
    
    glRotatef(phi / math.pi*180, p[0][0], p[0][1], p[0][2])
    
    # Iscrtavanje koordinata
    glBegin(GL_LINES)
    
    # x koordinata
    glColor3f(1, 0, 0)
    glVertex3f(0, 0, 0)
    glVertex3f(4, 0, 0)
        
    # y koordinata
    glColor3f(0, 1, 0)
    glVertex3f(0, 0, 0)
    glVertex3f(0, 4, 0)
        
    # z koordinata   
    glColor3f(0, 0, 1)
    glVertex3f(0, 0, 0)
    glVertex3f(0, 0, 4)
    
    glEnd()
    
    glPopMatrix()


def main():

    glutInit(sys.argv)

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB)
    glutInitWindowSize(600, 600)
    glutCreateWindow("SLERP")

    glLineWidth(4)    
    glClearColor(0.9, 0.9, 0.9, 1)
    glEnable(GL_DEPTH_TEST)
    
    glutKeyboardFunc(keyboard)
    glutDisplayFunc(display)

    if animation_ongoing:
        glutTimerFunc(TIMER_INTERVAL, timer, TIMER_ID)
       
    global q1
    global q2

    # ----------------------------------------
    
    A = Euler2A(beginAngles[0], beginAngles[1], beginAngles[2])
    p, phi = AxisAngle(A)
    q1 = AxisAngle2Q(p, phi)
    
    A = Euler2A(endAngles[0], endAngles[1], endAngles[2])
    p, phi = AxisAngle(A)
    q2 = AxisAngle2Q(p, phi)

    # ----------------------------------------
    
    glutMainLoop()
    return


if __name__ == '__main__': 
    main()