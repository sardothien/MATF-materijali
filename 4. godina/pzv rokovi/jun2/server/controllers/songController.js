const mongoose = require('mongoose');
const Song = require('../models/songs');

module.exports.getAllSongs = async (req, res, next) => {

    const sortBy = req.params.sortBy;

    try {

        const songs = await Song.find({}).sort(sortBy).exec();
        if(!songs) {
            res.status(500).json();
        }
        else {
            res.status(200).json(songs);
        }   

    } catch(err) {
        next(err);
    }
};

module.exports.patchSongCount = async (req, res, next) => {

    const id = req.body.id;
    if(!id) {
        res.status(500).json({ message: "id missing" });
        return ;
    }

    try {
        const song = await Song.findById(id).exec();
        if(!song) {
            res.status(500).json({ message: "song can't be found" });
        }
        else {
            song.count += 1;
            await song.save();
            res.status(200).json(song);
        }

    } catch(err) {
        next(err);
    }
}

module.exports.putNewSong = async (req, res, next) => {

    const artist = req.body.artist;
    const title = req.body.title;
    if(!artist || !title) {
        res.status(500).json({message: "artist or title missing"});
        return ;
    }

    try {
        const song = await Song.find({ artist: artist, title: title }).exec();
        if(song.length != 0) {
            res.status(309).json({ message: "The song already exists! Try again!" });
        }
        else {
            const newSong = new Song({
                _id: new mongoose.Types.ObjectId,
                artist: artist,
                title: title,
                count: 1
            });
            await newSong.save();

            res.status(201).json({ message: "The song has successfully been scrobbled!" });
        }

    } catch(err) {
        next(err);
    }
}