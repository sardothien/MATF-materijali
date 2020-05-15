% Napisati M-fajl matrica.m sa funkcijom M = matrica(n) koja
% vraca matricu M=(m_i,j) dimenzije nxn gde su prvo elementi 
% m_i,j definisani tako da vazi m_i,j = (-1)^(i+j)*i^2-j^3 a
% zatim, za n >= 3 i k = n/3 i m = n/2 (ako k i m nisu celobrojne
% vrednosti, zaokruziti ih na celobrojne), u matrici M zameniti mesta
% k-toj koloni i m-toj vrsti. Element M(k,m) ostaviti da bude isti kao
% u polaznoj matrici.
function M = matrica(n)

M = zeros(n);
for i = 1:n
   for j = 1:n
      if mod(i+j, 2) == 0
          M(i,j) = i^2 - j^3;
      else
         M(i,j) = -i^2 - j^3;  
      end
   end
end

if n > 3
   k = floor(n/3);
   m = floor(n/2);
   sacuvano = M(m, k);
   
   pom = M(:,k);
   M(:,k) = M(m,:)';
   M(m,:) = pom;
   
   M(m,k) = sacuvano;
end