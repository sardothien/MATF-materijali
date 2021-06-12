export class Payment {
    constructor(public _id: string, public name: string,
                public surname: string, public email: string,
                public amounts: number[]) 
    {}
}

export class PaymentId {
    constructor(public _id: string, public amounts: number[]) 
    {}
}