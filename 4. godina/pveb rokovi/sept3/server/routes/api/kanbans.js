const express = require('express');
const router = express.Router();
const controller = require('../../controllers/kanbansController');

router.get('', controller.getAllUncompletedTasks);
router.post('', controller.postNewKanban);
router.patch('/:id', controller.patchIncrementCompletedTasks);

module.exports = router;
