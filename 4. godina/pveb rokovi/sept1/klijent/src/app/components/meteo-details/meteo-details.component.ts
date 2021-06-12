import { Component, OnInit } from '@angular/core';
import { MeteoService } from 'src/app/services/meteo.service';
import { Meteo } from 'src/app/models/meteo.model';
import { FormGroup, FormBuilder, Validators } from '@angular/forms';
import { ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-meteo-details',
  templateUrl: './meteo-details.component.html',
  styleUrls: ['./meteo-details.component.css']
})
export class MeteoDetailsComponent implements OnInit {

  public meteo: Meteo = null;
  public tempRestrictions: FormGroup;
  public reset: boolean = false;
  public filteredTemperatures: number[] = [];
  public updateSuccess: string = '';
  public error: boolean = false;

  constructor(private meteoService: MeteoService,
              private formBuilder: FormBuilder,
              private route: ActivatedRoute) {
      
    this.tempRestrictions = this.formBuilder.group({
      filter: ['end', []],
      numberOfValues: ['', [Validators.required, Validators.pattern('[0-9]+')]]
    });

    const city = this.findByCity();
    this.meteoService.getCityMeteo(city).subscribe(
      (c: any) => {
        if(c.length != undefined && c.length === 0) {
          this.error = true;
        }
        else {
          this.error = false;
          this.meteo = c[0];
          this.filteredTemperatures = this.meteo.temperatures;
        }
      },
      err => {
        this.error = true;
      }
    );
  }

  ngOnInit() {
    
  }

  private findByCity() {
    let city: string = "";
    this.route.paramMap.subscribe(params => {
      city = params.get('city');
    });
    return city;
  }

  showFiltered(restrictions){
    this.reset = true;

    if(!this.tempRestrictions.valid){
      window.alert("Check the values!");
      return ;
    }

    let num: number = restrictions['numberOfValues'];

    if(restrictions['filter'] == 'end'){
      this.filteredTemperatures = this.meteo.temperatures.slice(this.meteo.temperatures.length - num, this.meteo.temperatures.length);
    } 
    else {
      this.filteredTemperatures = this.meteo.temperatures.slice(0, num);
    }
  }

  resetTemperatures() {
    this.filteredTemperatures = this.meteo.temperatures;
  }

  saveFilteredResults() {
    const obj = { city: this.meteo.city,  temperatures: this.filteredTemperatures};
    this.meteoService.putChangeTemperatures(obj).subscribe(
      (c: any) => {
        this.updateSuccess = c.message;
      }
    );
  }
}
