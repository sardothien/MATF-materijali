import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Observable } from 'rxjs';
import { Kanban } from '../models/kanban.model';

@Injectable({
  providedIn: 'root'
})
export class KanbanService {

  private url = 'http://localhost:3000/kanbans';

  constructor(private http: HttpClient) { }

  public getAllTasks(): Observable<Kanban[]> {
    return this.http.get<Kanban[]>(this.url);
  }

  public postNewKanban(obj: any): Observable<Kanban> {
    return this.http.post<Kanban>(this.url, obj);
  }

  public patchIncrementCompletedTasks(id: string): Observable<Kanban> {
    return this.http.patch<Kanban>(this.url + '/' + id, null);
  }
}
