export class Kanban {
    public constructor(public _id: string, public title: string,
                       public description: string,
                       public numOfSubtasks: number, public completedSubtasks: number)
    {}
}