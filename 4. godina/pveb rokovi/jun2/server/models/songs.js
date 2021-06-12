const mongoose = require('mongoose');

const songSchema = mongoose.Schema({
    _id: mongoose.Types.ObjectId,
    artist: {
        type: String,
        required: true
    },
    title: {
        type: String,
        required: true
    },
    count: {
        type: Number,
        required: true,
        default: 1
    }
});

const songModel = mongoose.model('Song', songSchema);

module.exports = songModel;