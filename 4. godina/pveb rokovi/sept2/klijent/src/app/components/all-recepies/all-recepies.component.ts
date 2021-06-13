import { Component, OnInit } from '@angular/core';
import { DessertsService } from 'src/app/services/desserts.service';
import { Dessert } from 'src/app/models/dessert.model';

@Component({
  selector: 'app-all-recepies',
  templateUrl: './all-recepies.component.html',
  styleUrls: ['./all-recepies.component.css']
})
export class AllRecepiesComponent implements OnInit {

  public desserts: Dessert[] = [];

  constructor(private dessertService: DessertsService) { 
    this.dessertService.getAllDesserts().subscribe(
      (c:any) => {
        this.desserts = c;
      }
    )
  }

  ngOnInit(): void {
  }

}
