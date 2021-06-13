import { Component, OnInit } from '@angular/core';
import { DessertsService } from 'src/app/services/desserts.service';
import { ActivatedRoute } from '@angular/router';
import { Dessert } from 'src/app/models/dessert.model';

@Component({
  selector: 'app-special-recepies',
  templateUrl: './special-recepies.component.html',
  styleUrls: ['./special-recepies.component.css']
})
export class SpecialRecepiesComponent implements OnInit {

  public criterion: string;
  public desserts: Dessert[] = [];
  public correctCriterion: boolean = true;

  constructor(private dessertService: DessertsService,
              private route: ActivatedRoute) { }

  ngOnInit(): void {
    this.getCriterion();
    this.dessertService.getDessertsByCriterion(this.criterion).subscribe(
      (c:any) => {
        this.correctCriterion = true;
        this.desserts = c;
      },
      (err: any) => {
        this.correctCriterion = false;
      }
    );
  }

  private getCriterion(){
    this.route.paramMap.subscribe(params => {
      this.criterion = params.get('criterion');
    });
  }

}
