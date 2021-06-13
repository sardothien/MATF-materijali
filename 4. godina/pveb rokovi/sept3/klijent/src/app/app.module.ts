import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { FormsModule, ReactiveFormsModule } from '@angular/forms';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { NavigationComponent } from './components/navigation/navigation.component';
import { HttpClientModule } from '@angular/common/http';
import { KanbanListComponent } from './components/kanbanlist/kanbanlist.component';
import { KanbanComponent } from './components/kanban/kanban.component';
import { NewKanbanComponent } from './components/new-kanban/new-kanban.component';

@NgModule({
  declarations: [
    AppComponent,
    NavigationComponent,
    KanbanListComponent,
    KanbanComponent,
    NewKanbanComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    FormsModule,
    ReactiveFormsModule,
    HttpClientModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
