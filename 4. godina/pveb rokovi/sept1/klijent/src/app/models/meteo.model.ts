export class Meteo {
    public constructor(public _id: string, public city: string,
                       public country: string, public temperatures: number[])
    {}
}