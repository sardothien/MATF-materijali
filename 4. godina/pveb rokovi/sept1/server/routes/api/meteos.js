const express = require('express');
const router = express.Router();
const controller = require('../../controllers/meteoController');

router.get('', controller.getAllMeteos);
router.get('/:city', controller.getCityMeteos);
router.put('', controller.putChangeTemperatures);

module.exports = router;
