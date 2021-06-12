import { Component, OnInit, Input } from '@angular/core';
import { Song } from 'src/app/models/song.model';
import { SongService } from 'src/app/services/song.service';

@Component({
  selector: 'app-song',
  templateUrl: './song.component.html',
  styleUrls: ['./song.component.css']
})
export class SongComponent implements OnInit {

  @Input()
  public song: Song;

  constructor(private songService: SongService) { }

  ngOnInit(): void {
  }

  incrementCount(id: string) {
    this.songService.patchSongCount(id).subscribe(
      c => {
        this.song = c;
      },
      err => {
        console.log(err);
      }
    )
  }

}
