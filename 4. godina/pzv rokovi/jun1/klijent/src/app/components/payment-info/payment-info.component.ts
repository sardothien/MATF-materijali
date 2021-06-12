import { Component, OnInit } from '@angular/core';
import { PaymentsService } from 'src/app/services/payments.service';
import { ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-payment-info',
  templateUrl: './payment-info.component.html',
  styleUrls: ['./payment-info.component.css']
})
export class PaymentInfoComponent implements OnInit {

  public amounts: number[] = [];

  constructor(private paymentService: PaymentsService,
              private route: ActivatedRoute) { }

  findById() {
    let id: string = "";
    this.route.paramMap.subscribe(params =>{
      id = params.get('id');
    });
    
    return this.paymentService.getPaymentById(id).toPromise();
  }

  async ngOnInit() {
    let obj = await this.findById();
    this.amounts = obj.amounts;
  }
}
