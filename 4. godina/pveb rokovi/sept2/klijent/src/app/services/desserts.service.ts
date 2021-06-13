import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Observable } from 'rxjs';
import { Dessert } from '../models/dessert.model';

@Injectable({
  providedIn: 'root'
})
export class DessertsService {

  private url = 'http://localhost:3000/desserts';

  constructor(private http: HttpClient) { }

  public getAllDesserts(): Observable<Dessert[]> {
    return this.http.get<Dessert[]>(this.url);
  }

  public getDessertsByCriterion(criterion: string): Observable<Dessert[]> {
    return this.http.get<Dessert[]>(this.url + '/' + criterion);
  }

  public postNewDessert(obj: any): Observable<Dessert> {
    return this.http.post<Dessert>(this.url, obj);
  }
}
