<?php
/**
 * @file
 * A description of what your module does.
 */

/**
 * System settings form handler.
 */
function fixer_io_settings() {

  $iso_codes = array(
    'AUD',
    'BGN',
    'BRL',
    'CAD',
    'CHF',
    'CNY',
    'CZK',
    'DKK',
    'EUR',
    'GBP',
    'HKD',
    'HRK',
    'HUF',
    'IDR',
    'ILS',
    'INR',
    'JPY',
    'KRW',
    'MXN',
    'MYR',
    'NOK',
    'NZD',
    'PHP',
    'PLN',
    'RON',
    'RUB',
    'SEK',
    'SGD',
    'THB',
    'TRY',
    'USD',
    'ZAR',
  );

  $form['fixer_io_base'] = array(
    '#type' => 'select',
    '#title' => t('Choose a base currency.'),
    '#options' => drupal_map_assoc($iso_codes),
    '#default_value' => variable_get('fixer_io_base', 'EUR'),
  );
  $form['fixer_io_options'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Choose switchable currencies.'),
    '#options' => drupal_map_assoc($iso_codes),
    '#default_value' => variable_get('fixer_io_options', array('EUR', 'USD', 'GBP')),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * System settings submit handler.
 */
function fixer_io_settings_submit($form, &$form_state) {

  variable_set('fixer_io_base', $form_state['values']['fixer_io_base']);
  variable_set('fixer_io_options', $form_state['values']['fixer_io_options']);
  _fixer_io_reload();
}
