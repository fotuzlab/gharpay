<?php

/**
 * @file
 * Create order using Gharpay.
 */

/**
 * Create order form.
 */
function gharpay_create_order_form($form, &$form_state) {

  $form['gharpay_create_order_customer_details'] = array(
    '#type' => 'fieldset',
    '#title' => t("Customer details"),
    );
  $form['gharpay_create_order_customer_details']['contact'] = array(
    '#type' => 'textfield',
    '#title' => t("Contact"),
    '#required' => TRUE,
    '#description' => t("Your contact number."),
    );
  $form['gharpay_create_order_customer_details']['prefix'] = array(
    '#type' => 'select',
    '#title' => t("Prefix"),
    '#options' => array(
        'mr' => t("Mr."),
        'ms' => t("Ms."),
        'mrs' => t("Mrs."),
        'dr' => t("Dr."),
        'prof' => t("Prof."),
      ),
    );
  $form['gharpay_create_order_customer_details']['firstname'] = array(
    '#type' => 'textfield',
    '#title' => t("First name"),
    '#required' => TRUE,
    );
  $form['gharpay_create_order_customer_details']['lastname'] = array(
    '#type' => 'textfield',
    '#title' => t("Last name"),
    );
  $form['gharpay_create_order_customer_details']['address'] = array(
    '#type' => 'textarea',
    '#title' => t("Address"),
    '#required' => TRUE,
    );
  $form['gharpay_create_order_order_details'] = array(
    '#type' => 'fieldset',
    '#title' => t("Order details"),
    );
  $form['gharpay_create_order_order_details']['pin'] = array(
    '#type' => 'select',
    '#title' => t("Pincode"),
   // '#options' => gharpay_get_all_pincodes_cities(),
    );

  return system_settings_form($form);
}

/**
 * Make http request.
 */
function gharpay_http_request($url, $data = NULL) {
  $request = drupal_http_request(
    $url,
    array(
      'username' => USERNAME,
      'password' => PASSWORD,
      ),
    'GET',
    $data,
    3,
    30
  );
  return $request;
}

function gharpay_get_all_pincodes_cities() {
  $url = URL . "/rest/GharpayService/getAllPincodesWithCity";
  $request = gharpay_http_request($url, $data = NULL);
  return $request;
}

$test = new GharpayAPI();
$test2 = $test->getPincodesInCity('mumbai');
print_r($test2); die();
