import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { HomeComponent } from './components/home/home.component';
import { PaymentInfoComponent } from './components/payment-info/payment-info.component';


const routes: Routes = [
  {path: '', component: HomeComponent},
  {path: 'payment/:id', component: PaymentInfoComponent}
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
