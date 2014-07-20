#Drupal Color Styles

Color Styles is a custom Drupal module with an admin settings page and ctools panels plugin using jquery colorpicker. This module is really just an example to show what's possible with the jquery colorpicker FAPI element and leveraging that in a ctools custom panels pane plugin.

The content type plugin with this module pulls the saved settings into a panel pane via the ctools plugin technology. The colors the user selects for title and title background are then rendered as the title in the panel pane. 

The colorpicker FAPI element looks like this:

```
 $form['message']['colors']['title_color'] = array(
    '#type' => 'jquery_colorpicker',
    '#title' => t('Title color'),
    '#default_value' => variable_get('color_styles_title_color', ''),
    '#description' => t('Set the title color'),
  );
```

Then in the plugin, we can retrieve that info and render it in output. e.g.:


```
$title_color = variable_get('color_styles_title_color');
```

```
 if (isset($message_title)) {
    $output[] = '<h2 style="color: #' . $title_color . ' ; background-color: #' . $title_bg . ' " class="help-text-wrapper"> ';
    $output[] = $message_title;
    $output[] = '</h2>';
  }
```




