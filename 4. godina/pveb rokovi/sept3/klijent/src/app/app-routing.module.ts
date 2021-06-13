import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { KanbanListComponent } from './components/kanbanlist/kanbanlist.component';
import { NewKanbanComponent } from './components/new-kanban/new-kanban.component';


const routes: Routes = [
  {path: '', component: KanbanListComponent},
  {path: 'add-a-kanban', component: NewKanbanComponent}
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
