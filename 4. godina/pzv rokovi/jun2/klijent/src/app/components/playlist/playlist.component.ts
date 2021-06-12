import { Component, OnInit } from '@angular/core';
import { SongService } from 'src/app/services/song.service';
import { Song } from 'src/app/models/song.model';

interface option {
  id: number;
  name: string;
}

@Component({
  selector: 'app-playlist',
  templateUrl: './playlist.component.html',
  styleUrls: ['./playlist.component.css']
})
export class PlaylistComponent implements OnInit {

  public options: option[];
  public selectedOption: option;
  public songs: Song[] = [];

  constructor(private songService: SongService) { 
    this.options = [
      {id: 1, name: ""},
      {id: 2, name: "artist"},
      {id: 3, name: "title"},
      {id: 4, name: "count"}
    ]
  }

  ngOnInit(): void {
  }

  getSongs(sortBy) {
    if(sortBy.name == "") {
      return ;
    }

    this.songService.getAllSongs(sortBy.name).subscribe(
      c => {
        this.songs = c;
      },
      err => {
        console.log("Error");
      }
    )
  }
}
