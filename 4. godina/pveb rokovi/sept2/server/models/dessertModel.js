const mongoose = require('mongoose');

const dessertsSchema = mongoose.Schema({
    _id: mongoose.Types.ObjectId,
    name: {
        type: String,
        require: true
    },
    description: {
        type: String,
        require: true,
        maxlength: 200
    },
    complexity: {
        type: String,
        require: true,
        enum: ['easy', 'medium', 'hard']
    },
    nutrition: {
        type: Number,
        require: true
    },
    glutenFree: {
        type: Boolean
    }
});

const dessertsModel = mongoose.model('Dessert', dessertsSchema);

module.exports = dessertsModel;