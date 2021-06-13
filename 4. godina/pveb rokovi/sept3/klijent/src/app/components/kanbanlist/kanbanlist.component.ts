import { Component, OnInit } from '@angular/core';
import { Kanban } from 'src/app/models/kanban.model';
import { KanbanService } from 'src/app/services/kanban.service';

@Component({
  selector: 'app-kanbanlist',
  templateUrl: './kanbanlist.component.html',
  styleUrls: ['./kanbanlist.component.css']
})
export class KanbanListComponent implements OnInit {

  public kanbans: Kanban[];

  constructor(private kanbanService: KanbanService) { }

  ngOnInit(): void {
    this.kanbanService.getAllTasks().subscribe(
      (c:any) => {
        this.kanbans = c;
      }
    )
  }

}
