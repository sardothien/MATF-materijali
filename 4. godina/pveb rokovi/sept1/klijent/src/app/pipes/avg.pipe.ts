import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'avg'
})
export class AvgPipe implements PipeTransform {

  transform(items: any, attr: string): any {
    let sum = items.reduce((a,b) => a + b, 0);
    return sum / items.length;
  }

}
