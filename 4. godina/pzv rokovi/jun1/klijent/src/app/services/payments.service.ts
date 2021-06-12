import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Observable } from 'rxjs';
import { Payment, PaymentId } from '../models/payment.model';

@Injectable({
  providedIn: 'root'
})
export class PaymentsService {

  private serverLink: string = "http://localhost:3000/payments";

  constructor(private http: HttpClient) { }

  getPaymentByEmail(email: string): Observable<Payment> {
    return this.http.get<Payment>(this.serverLink + "/email/" + email);
  }

  getPaymentById(id: string): Observable<PaymentId> {
    return this.http.get<Payment>(this.serverLink + "/id/" + id);
  }

  patchAddAmount(id:string, amount: number) {
    const obj = {id, amount};
    return this.http.patch<Payment>(this.serverLink, obj);
  }
}
