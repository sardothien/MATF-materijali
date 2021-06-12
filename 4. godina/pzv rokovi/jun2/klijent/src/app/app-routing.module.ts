import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { HomeComponent } from './components/home/home.component';
import { NewSongComponent } from './components/new-song/new-song.component';


const routes: Routes = [
  {path: '', component: HomeComponent},
  {path: 'scrobble', component: NewSongComponent}
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
