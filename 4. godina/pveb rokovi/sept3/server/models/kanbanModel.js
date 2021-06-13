const mongoose = require('mongoose');

const kanbanSchema = mongoose.Schema({
    _id: mongoose.Types.ObjectId,
    title: {
        type: String,
        require: true
    },
    description: {
        type: String,
        require: true
    },
    numOfSubtasks: {
        type: Number,
        require: true
    },
    completedSubtasks: {
        type: Number,
        require: true,
        default: 0
    }
});

const kanbanModel = mongoose.model('Kanban', kanbanSchema);

module.exports = kanbanModel;