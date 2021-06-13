import { Component, OnInit, Input } from '@angular/core';
import { Kanban } from 'src/app/models/kanban.model';
import { KanbanService } from 'src/app/services/kanban.service';

@Component({
  selector: 'app-kanban',
  templateUrl: './kanban.component.html',
  styleUrls: ['./kanban.component.css']
})
export class KanbanComponent implements OnInit {
  @Input()
  public kanban: Kanban;
  public percentage: number;
  public showKanban: boolean = true;

  constructor(private kanbanService: KanbanService) { }

  ngOnInit(): void {
    this.showKanban = true;
    if(this.kanban.completedSubtasks >= this.kanban.numOfSubtasks) {
      this.showKanban = false;
    }
    this.percentage = this.kanban.completedSubtasks / this.kanban.numOfSubtasks * 100;
  }

  public incSubtasks(id: string) {
    this.kanbanService.patchIncrementCompletedTasks(id).subscribe(
      (c:any) => {
        if(this.kanban.completedSubtasks >= this.kanban.numOfSubtasks) {
          this.showKanban = false;
        }
        window.location.reload();
      }
    )
  }
}
