<?php
/**
 * @file
 * A description of what your module does.
 */

/**
 * @return mixed
 */
function fixer_io_base() {

  $form['fixer_io_base'] = array(
    '#type'          => 'select',
    '#title'         => t('Choose a base currency.'),
    '#description'   => t('Being the currency of the base values in the back-end.'),
    '#options'       => _fixer_io_available_currencies(),
    '#default_value' => variable_get('fixer_io_base', 'EUR'),
  );

  $form['submit'] = array(
    '#type'  => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * @param $form
 * @param $form_state
 */
function fixer_io_base_submit($form, &$form_state) {

  variable_set('fixer_io_base', $form_state['values']['fixer_io_base']);

  _fixer_io_reload();
}

/**
 * @return mixed
 */
function fixer_io_options() {

  $form['fixer_io_options'] = array(
    '#type'          => 'checkboxes',
    '#title'         => t('Choose switchable currencies.'),
    '#options'       => _fixer_io_available_currencies(),
    '#default_value' => variable_get('fixer_io_options', array(
      'EUR',
      'USD',
      'GBP',
    )),
  );

  return system_settings_form($form);
//  variable_set('fixer_io_options', $form_state['values']['fixer_io_options']);
}

/**
 * System settings form handler.
 */
function fixer_io_default() {

  $form['fixer_io_default'] = array(
    '#type' => 'container',
  );
  $form['fixer_io_default']['description'] = array(
    '#prefix' => '<label>',
    '#markup' => t('Choose a default display currency for each available language.'),
    '#suffix' => '</label>',
  );

  $languages = language_list();
  $default_array = variable_get('fixer_io_default', 'EUR');

  foreach ($languages as $language) {

    $default_value = is_array($default_array) ? $default_array[$language->language] : $default_array;

    $form['fixer_io_default']['fixer_io_default_' . $language->language] = array(
      '#type'          => 'select',
      '#description'   => count($languages) > 1 ? $language->name : '',
      '#options'       => _fixer_io_activated_currencies(),
      '#default_value' => $default_value,
    );
  }

  $form['submit'] = array(
    '#type'  => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * System settings submit handler.
 */
function fixer_io_default_submit($form, &$form_state) {

  $default_currency = array();
  foreach ($form_state['values'] as $key => $value) {
    if (strpos($key, 'fixer_io_default_') !== FALSE) {
      $prefix = str_replace('fixer_io_default_', '', $key);
      $default_currency[$prefix] = $value;
    }
  }
  variable_set('fixer_io_default', $default_currency);

}

/**
 * Helper function to return all available currencies as
 * three-letter ISO code strings.
 *
 * @return array
 */
function _fixer_io_available_currencies() {

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

  return drupal_map_assoc($iso_codes);
}
