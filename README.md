# Drupal Color Styles Example

Color Styles is a custom Drupal module with an admin settings page and ctools panels plugin using jquery colorpicker. This module is really just an example to show what's possible with the jquery colorpicker FAPI element and leveraging that in a ctools custom panels pane plugin.

The content type plugin with this module pulls the saved settings into a panel pane via the ctools plugin technology. The colors the user selects for title and title background are then rendered as the title in the panel pane. 

The colorpicker FAPI element looks like this:

```php
 $form['message']['colors']['title_color'] = array(
    '#type' => 'jquery_colorpicker',
    '#title' => t('Title color'),
    '#default_value' => variable_get('color_styles_title_color', ''),
    '#description' => t('Set the title color'),
  );
```

Then in the plugin, we can retrieve that info and render it in output. e.g.:


```php
$title_color = variable_get('color_styles_title_color');
```

```php
 if (isset($message_title)) {
    $output[] = '<h2 style="color: #' . $title_color . ' ; background-color: #' . $title_bg . ' " class="help-text-wrapper"> ';
    $output[] = $message_title;
    $output[] = '</h2>';
  }
```

To use this module, you'll need a basic Drupal 7 site with the following contrib modules: 
* Ctools
* Panels
* jQuery colorpicker
* Libraries
* [jQuery colorpicker library](http://www.eyecon.ro/colorpicker/#download)

To get up and running:

1. ``` git clone git@github.com:highrockmedia/drupal-color-styles.git``` and put this in your /sites/all/modules or /sites/all/modules/custom.
2. ```drush dl ctools, panels, jquery_colorpicker, libraries```
3. Get the colorpicker library and follow the install instructions from the jquery_colorpicker drupal module's readme.
4. ```drush en color_styles```
5. Visit the settings page link from the modules admin page
6. Configure settings
7. Configure a basic panels page.
8. Add *Message Pane* from the Custom profile group in your panes choice dialog.
9. Save and view your new page with custom message, title and styled colors. You'll want to add other content to this page as well. 








