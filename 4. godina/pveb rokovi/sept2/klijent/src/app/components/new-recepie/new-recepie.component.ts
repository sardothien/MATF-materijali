import { Component, OnInit } from '@angular/core';
import { DessertsService } from 'src/app/services/desserts.service';
import { FormGroup, FormBuilder, Validators } from '@angular/forms';

@Component({
  selector: 'app-new-recepie',
  templateUrl: './new-recepie.component.html',
  styleUrls: ['./new-recepie.component.css']
})
export class NewRecepieComponent implements OnInit {

  public newRecepieForm: FormGroup;

  constructor(private dessertService: DessertsService,
              private formBuilder: FormBuilder) {

    this.newRecepieForm = this.formBuilder.group({
      name: ['', [Validators.required]],
      description: ['', [Validators.required, Validators.maxLength(200)]],
      complexity: ['', [Validators.required]],
      nutrition: ['', [Validators.required, Validators.pattern("[0-9]+")]],
      glutenFree: [false,]
    });
  }

  ngOnInit(): void {
  }

  saveRecepie(newRecepie) {

    if(!this.newRecepieForm) {
      window.alert("Form is invalid - please check the inputs!");
      return ;
    }
    console.log(newRecepie);
    this.dessertService.postNewDessert(newRecepie).subscribe(
      (c: any) => {
        window.alert('Recepie is successfuly added!');
      }
    )
  }
}
