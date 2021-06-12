import { Component, OnInit } from '@angular/core';
import { FormGroup, FormBuilder, Validators } from '@angular/forms';
import { PaymentsService } from 'src/app/services/payments.service';
import { Payment } from 'src/app/models/payment.model';
import { Router } from '@angular/router';

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.css']
})
export class HomeComponent implements OnInit {

  public error: boolean = false;
  public empty: boolean = true;
  public found: boolean = false;

  public emailForm: FormGroup;
  public amountForm: FormGroup;

  public payment: Payment;

  constructor(private paymentService: PaymentsService,
              private formBuilder: FormBuilder,
              private router: Router) { 
    
    this.emailForm = this.formBuilder.group({
      email: ['', [Validators.required, Validators.email]]
    });

    this.amountForm = this.formBuilder.group({
      amount: ['', [Validators.required, Validators.min(1000)]]
    });
  }

  ngOnInit(): void {
  }

  search(email: string) {
    if(!this.emailForm.valid){
      this.empty = true;
      window.alert("Formular nije validan! Ispraviti podatke.");
      return ;
    }

    this.paymentService.getPaymentByEmail(email['email']).subscribe(
      async c => {
        this.payment = c[0];
        if(!this.payment){
          this.error = true;
        }
        else {
          this.error = false;
          this.found = true;
        }
        this.empty = false;
      },
      (err) => {
        this.error = true;
      }
    );
  }

  addNewAmount(id, amount) {
    if(!this.amountForm.valid){
      window.alert("Formular nije validan! Ispraviti podatke.");
      return ;
    }

    this.paymentService.patchAddAmount(id, amount.amount).subscribe(
      c => {
        window.alert("Uspesno dodavanje kolicine");
      },
      err => {
        console.log("Error");
      });
  }
}
