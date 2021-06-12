import { Component, OnInit } from '@angular/core';
import { MeteoService } from 'src/app/services/meteo.service';
import { Meteo } from 'src/app/models/meteo.model';

@Component({
  selector: 'app-meteo',
  templateUrl: './meteo.component.html',
  styleUrls: ['./meteo.component.css']
})

export class MeteoComponent implements OnInit {

  public meteos: Meteo[] = [];

  constructor(public meteoService: MeteoService) {}

  ngOnInit(): void {
    this.meteoService.getAllMeteos().subscribe(
      (c: any) => {
        this.meteos = c;
      },
      err => {

      }
    );
  }

}
