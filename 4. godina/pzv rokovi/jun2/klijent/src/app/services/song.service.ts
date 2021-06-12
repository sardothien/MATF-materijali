import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Observable } from 'rxjs';
import { Song } from '../models/song.model';

@Injectable({
  providedIn: 'root'
})
export class SongService {

  public url: string = "http://localhost:3000/songs/"

  constructor(private http: HttpClient) { }

  public getAllSongs(sortBy: string): Observable<Song[]> {
    return this.http.get<Song[]>(this.url + sortBy);
  }

  public patchSongCount(id: string): Observable<Song> {
    return this.http.patch<Song>(this.url, {id});
  }

  public putNewSong(obj): Observable<Song> {
    return this.http.put<Song>(this.url, obj);
  }
}
