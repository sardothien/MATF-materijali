const express = require('express');
const router = express.Router();
const controller = require('../../controllers/songController');

router.get('/:sortBy', controller.getAllSongs);
router.patch('/', controller.patchSongCount);
router.put('/', controller.putNewSong);

module.exports = router;
