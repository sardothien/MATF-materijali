import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { MeteoComponent } from './components/meteo/meteo.component';
import { MeteoDetailsComponent } from './components/meteo-details/meteo-details.component';


const routes: Routes = [
  {path: '', component: MeteoComponent},
  {path: 'details/:city', component: MeteoDetailsComponent}
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
