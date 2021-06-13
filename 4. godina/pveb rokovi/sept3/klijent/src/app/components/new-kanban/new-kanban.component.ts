import { Component, OnInit } from '@angular/core';
import { FormGroup, FormBuilder, Validators } from '@angular/forms';
import { KanbanService } from 'src/app/services/kanban.service';

@Component({
  selector: 'app-new-kanban',
  templateUrl: './new-kanban.component.html',
  styleUrls: ['./new-kanban.component.css']
})
export class NewKanbanComponent implements OnInit {

  public newKanbanForm: FormGroup;

  constructor(private kanbanService: KanbanService,
              private formBuilder: FormBuilder) {
    this.newKanbanForm = this.formBuilder.group({
      title: ['', [Validators.required]],
      description: ['', [Validators.required]],
      numOfSubtasks: ['', [Validators.required, Validators.min(5)]]
    });
  }

  ngOnInit(): void {
  }

  addNewKanban(newKanban) {
    if(!this.newKanbanForm.valid) {
      window.alert('The form is not valid!');
      return ;
    }

    console.log(newKanban);

    this.kanbanService.postNewKanban(newKanban).subscribe(
      (c:any) => {
        window.alert(c.message);
        this.newKanbanForm.reset();
      }
    )
  }

}
