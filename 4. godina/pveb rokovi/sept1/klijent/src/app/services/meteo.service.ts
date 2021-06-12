import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Observable } from 'rxjs';
import { Meteo } from '../models/meteo.model';

@Injectable({
  providedIn: 'root'
})
export class MeteoService {

  private url = 'http://localhost:3000/meteos'

  constructor(private http: HttpClient) { }

  getAllMeteos(): Observable<Meteo[]> {
    return this.http.get<Meteo[]>(this.url);
  }

  getCityMeteo(city: string): Observable<Meteo> {
    return this.http.get<Meteo>(this.url + "/" + city);
  }

  putChangeTemperatures(obj): Observable<Meteo> {
    return this.http.put<Meteo>(this.url, obj);
  }
}
