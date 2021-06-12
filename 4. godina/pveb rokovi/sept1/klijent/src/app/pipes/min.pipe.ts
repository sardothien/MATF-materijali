import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'min'
})
export class MinPipe implements PipeTransform {

  transform(items: any, attr: string): any {
    return items.sort()[0];
  }

}
