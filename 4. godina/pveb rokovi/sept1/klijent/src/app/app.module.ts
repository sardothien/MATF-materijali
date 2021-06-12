import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { FormsModule, ReactiveFormsModule } from '@angular/forms';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { HeaderComponent } from './components/header/header.component';
import { HttpClientModule } from '@angular/common/http';
import { MeteoComponent } from './components/meteo/meteo.component';
import { MinPipe } from './pipes/min.pipe';
import { MaxPipe } from './pipes/max.pipe';
import { AvgPipe } from './pipes/avg.pipe';
import { MeteoDetailsComponent } from './components/meteo-details/meteo-details.component';

@NgModule({
  declarations: [
    AppComponent,
    HeaderComponent,
    MeteoComponent,
    MinPipe,
    MaxPipe,
    AvgPipe,
    MeteoDetailsComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    HttpClientModule,
    FormsModule,
    ReactiveFormsModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
