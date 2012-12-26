<?php

/**
 * @file
 * Configure settings for Gharpay.
 */

/**
 * Configuration form for Gharpay.
 */
function gharpay_config_form() {
  $form = array();

  // Allow only India based transactions.
  $form['gharpay_allow_only_in_india'] = array(
    '#type' => 'checkbox',
    '#title' => t("Pay using Gharpay only in India"),
    '#default_value' => variable_get('gharpay_allow_only_in_india', 0),
    '#description' => t("If selected, users only from India would be allowed to pay using Gharpay."),
    );

  $default_gharpay_description = t("Gharpay has an Indian network of executives to reach customer's doorsteps and accept payments.");
  // Add a description about Gharpay.
  $form['gharpay_description'] = array(
    '#type' => 'textarea',
    '#title' => t("Help text"),
    '#description' => t("Describe Gharpay's payment method. This would be shown to the customers. <i>Leave blank for no description</i>"),
    '#default_value' => variable_get('gharpay_description', $default_gharpay_description),
    );
  // Need to add processing function for this field.
  $form['gharpay_surcharge'] = array(
    '#type' => 'textfield',
    '#title' => t("Surcharge"),
    '#default_value' => variable_get('gharpay_surcharge', ''),
    '#description' => t("Add value in % or Rs. <i>e.g. 5% for value in percent or only 5 for value in Rs.</i>"),
    );

  return system_settings_form($form);
}