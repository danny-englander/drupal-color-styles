<?php

/**
 * @file
 * Handle rendering our custom message with color styles in a pane.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Message Pane'),
  'description' => t('Custom message pane with color settings.'),
  'category' => t('Custom panes'),
  'edit form' => 'color_styles_message_pane_edit_form',
  'render callback' => 'color_styles_message_pane_render',
  'all contexts' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function color_styles_message_pane_edit_form($form, &$form_state) {
  // @todo Move all of the admin-form here and ditch the hook_menu().
  //   You can use this form to present the stuff so the admin can
  //   configure the message text, title and foreground/background
  //   colors on a per-instance basis instead of globally. Note
  //   you will need to add a submit-handler too to move the input
  //   values from form_state into the pane conf.
  // Hide the pane title / override, we don't want it and it's not a required field.
  $form['override_title_text'] = array(
    '#type' => '',
  );

  $form['override_title'] = array(
    '#type' => '',
  );

  $form['override_title_markup'] = array(
    '#markup' => t(''),
  );

  return $form;

}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function color_styles_message_pane_render($subtype, $conf, $args, $contexts) {
  // Pull the vars from our admin settings page.
  // @todo Don't use global variables, get the values from $conf
  //   instead, once you've enabled per-instance configuration.
  $message_title = variable_get('color_styles_message_title');
  $title_color = variable_get('color_styles_title_color');
  $title_bg = variable_get('color_styles_title_bg');
  $message_text = variable_get('color_styles_message_text');

  // Define the output array.
  $output = array();

  // Render the title text if there's a value.
  if (isset($message_title)) {
    // The title color and background should be hex color codes. 
    $output[] = '<h2 style="color: #' . check_plain($title_color) . ' ; background-color: #' . check_plain($title_bg) . ' " class="message-title-wrapper"> ';
    // We are expecting the title to be plain-text, so make sure it is.
    $output[] = check_plain($message_title);
    $output[] = '</h2>';
  }

  // Render the message text if there's a value.
  if (isset($message_text['value'])) {
    $output[] = '<span class="message-text-wrapper"> ';
    // Make sure that the markup is consistent with the input format.
    $output[] = check_markup($message_text['value'], $message_text['format']);
    $output[] = '</span>';
  }

  // Render the final output.
  $block = new stdClass();
  $block->title = '';
  $block->content = implode('', $output);

  return $block;
}
