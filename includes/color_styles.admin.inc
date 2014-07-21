<?php


/**
 * Form callback for the global admin settings.
 */
function color_styles_admin_settings() {
  $form = array();

  // Fieldset wrapper.
  $form['message'] = array(
    '#type' => 'fieldset',
    '#title' => t('Messages'),
  );

  // Message title.
  $form['message']['message_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Message title'),
    '#default_value' => variable_get('color_styles_message_title', ''),
    '#required' => FALSE,
  );

  // Colors wrapper.
  $form['message']['colors']['wrapper_open'] = array(
    '#markup' => '<div class="color-wrapper">',
  );

  // Color picker fapi element for title color.
  $form['message']['colors']['title_color'] = array(
    '#type' => 'jquery_colorpicker',
    '#title' => t('Title color'),
    '#default_value' => variable_get('color_styles_title_color', ''),
    '#description' => t('Set the title color'),
  );

  // Color picker fapi element for title bg.
  $form['message']['colors']['title_bg'] = array(
    '#type' => 'jquery_colorpicker',
    '#title' => t('Title background'),
    '#default_value' => variable_get('color_styles_title_bg', ''),
    '#description' => t('Set the title background'),
  );

  // Closing wrapper.
  $form['message']['colors']['wrapper_closed'] = array(
    '#markup' => '</div>',
  );

  // Set a var for the text_format since text_format has issues with htmlspecialchars.
  // See https://www.drupal.org/node/1355242#comment-6086212
  $textformat = variable_get('color_styles_message_text', array(
    'value' => '',
    'format' => NULL
  ));

  // Message text area.
  $form['message']['message_text'] = array(
    '#type' => 'text_format',
    '#title' => t('Custom message'),
    '#required' => TRUE,
    '#rows' => 5,
    '#format' => $textformat['format'],
    '#default_value' => $textformat['value'],
    '#description' => t('Use this area to set a custom message'),
  );

  $form['actions'] = array(
    '#type' => 'actions',
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Settings'),
  );

  return $form;
}

/**
 * Submit handler for our admin settings.
 */
function color_styles_admin_settings_submit($form, &$form_state) {
  // Set keys that will be prefaced with our namespace.
  $keys = array(
    'message_title',
    'message_text',
    'title_color',
    'title_bg',
  );

  // Keys array.
  foreach ($keys as $key) {
    $value = isset($form_state['values'][$key]) ? $form_state['values'][$key] : array();
    variable_set('color_styles_' . $key, $value);
  }

  // Form saved message.
  drupal_set_message('Your settings have been saved.');
}
