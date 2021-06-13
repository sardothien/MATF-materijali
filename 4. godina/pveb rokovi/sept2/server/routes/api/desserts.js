const express = require('express');
const router = express.Router();
const controller = require('../../controllers/dessertController');

router.get('', controller.getAllDesserts);
router.get('/:criterion', controller.getDessertsByCriterion);
router.post('', controller.postNewDessert);

module.exports = router;
