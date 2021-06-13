const mongoose = require('mongoose');
const Kanban = require('../models/kanbanModel');

module.exports.getAllUncompletedTasks = async (req, res, next) => {

    try {
        const tasks = await Kanban.find({}).sort({'numOfSubtasks':1}).exec();
        res.status(200).json(tasks);

    } catch(err) {
        next(err);
    }
};

module.exports.postNewKanban = async (req, res, next) => {
    const title = req.body.title;
    const description = req.body.description;
    const numOfSubtasks = req.body.numOfSubtasks;
    if(!title || !description || !numOfSubtasks) {
        res.status(500).json({ message: "Some values missing" });
        return ;
    }

    try {
        const titleExists = await Kanban.findOne({ title: title }).exec();
        if(titleExists) {
            res.status(400).json({ message: "The kanban with the same title already exists!" });
        }
        else {
            const newKanban = new Kanban({
                _id: new mongoose.Types.ObjectId(),
                title: title,
                description: description,
                numOfSubtasks: numOfSubtasks
            });
            await newKanban.save();

            res.status(200).json({ message: "The kanban is successfully created!" });
        }

    } catch(err) {
        next(err);
    }
};

module.exports.patchIncrementCompletedTasks = async (req, res, next) => {
    const id = req.params.id;

    try {
        const kanban = await Kanban.findOne({ _id: id }).exec();
        if(!kanban) {
            res.status(404).json({ message: `The kanban with id ${id} does not exist!` });
        }
        else {
            kanban.completedSubtasks += 1;
            await kanban.save();
            res.status(200).json({ message: `A progress was made on kanban with id ${id}` });
        }

    } catch(err) {
        next(err);
    }
};