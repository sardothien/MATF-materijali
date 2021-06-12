import { Component, OnInit } from '@angular/core';
import { FormGroup, FormBuilder, Validators } from '@angular/forms';
import { SongService } from 'src/app/services/song.service';

@Component({
  selector: 'app-new-song',
  templateUrl: './new-song.component.html',
  styleUrls: ['./new-song.component.css']
})
export class NewSongComponent implements OnInit {

  public newSong: FormGroup;

  constructor(private songService: SongService,
              private formBuilder: FormBuilder) {
      this.newSong = this.formBuilder.group({
        artist: ['', [Validators.required]],
        title: ['', [Validators.required]]
      });
   }

  ngOnInit(): void {
  }

  addNewSong(song){
    if(!this.newSong.valid){
      window.alert("The form is not valid");
      return ;
    }

    this.songService.putNewSong(song).subscribe(
      (c: any) => {
        window.alert(c.message);
        this.newSong.reset();
      },
      err => {
        
      }
    )
  }
}
