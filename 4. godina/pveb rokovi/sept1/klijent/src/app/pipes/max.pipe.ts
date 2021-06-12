import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'max'
})
export class MaxPipe implements PipeTransform {

  transform(items: any, attr: string): any {
    return items.sort()[items.length-1];
  }

}
