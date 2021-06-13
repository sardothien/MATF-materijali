import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { HttpClientModule } from '@angular/common/http';
import { ReactiveFormsModule, FormsModule } from '@angular/forms';
import { NewRecepieComponent } from './components/new-recepie/new-recepie.component';
import { AllRecepiesComponent } from './components/all-recepies/all-recepies.component';
import { SpecialRecepiesComponent } from './components/special-recepies/special-recepies.component';

@NgModule({
  declarations: [
    AppComponent,
    NewRecepieComponent,
    AllRecepiesComponent,
    SpecialRecepiesComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    HttpClientModule,
    FormsModule,
    ReactiveFormsModule,
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
