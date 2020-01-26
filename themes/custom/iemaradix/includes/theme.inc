<?php

/**
 * @file
 * Custom theme hooks.
 */

/**
 * @file
 * Functions to support theming in the Redactive Base theme.
 */

use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Template\Attribute;
$theme_path = drupal_get_path('theme', 'redactive_base');


function redactive_base_preprocess_html(&$variables) {
  $theme_debug_val = theme_get_setting('debug_mode_layout')[0];
  $variables['debug_theme'] = $theme_debug_val;
}

function iemaradix_preprocess_page(&$variables){

  $tree = \Drupal::menuTree()->load('secondary-menu', new \Drupal\Core\Menu\MenuTreeParameters());
  $menucounter = 0;
  $menutreesample = array();

  foreach ($tree as $item) {
    $menutreesample[$menucounter]['title']     = $item->link->getTitle();
    $menutreesample[$menucounter]['url']       = $item->link->getUrlObject();
    $menutreesample[$menucounter]['children']  = $item->link->getUrlObject();
    $menucounter ++;
  }
  $variables['main_menu'] = $menutreesample;


  $homepage_first_news = \Drupal\block\Entity\Block::load('views_block__taxonomy_block_standfirst_block_1');
  $variables['jumbotron_news'] = \Drupal::entityManager()
          ->getViewBuilder('block')
          ->view($homepage_first_news);

  $homepage_next_two_news = \Drupal\block\Entity\Block::load('views_block__taxonomy_block_standfirst_block_2');
  $variables['next_two_news'] = \Drupal::entityManager()
          ->getViewBuilder('block')
          ->view($homepage_next_two_news);

  $editors_pick = \Drupal\block\Entity\Block::load('views_block__homepage_views_block_1');
  $variables['editors_pick'] = \Drupal::entityManager()
          ->getViewBuilder('block')
          ->view($editors_pick);

  // $theme_path = drupal_get_path('theme', 'redactive_base');
  // $theme_debug_val = theme_get_setting('debug_mode_layout')[0];
  // $variables['debug_theme'] = $theme_debug_val;
  // $header = 'header';
  //
  // if(!empty(theme_get_setting('header_skin'))){
  //   $header = theme_get_setting('header_skin');
  // }
  //
  // if(file_exists($theme_path . '/templates/includes/' . trim($header) . '.html.twig')){
  //   $variables['header_type'] = '/templates/includes/' . trim($header) . '.html.twig';
  // }
  //
  // // Get specific block type into variable.
  // $top_four_article_block = \Drupal\block\Entity\Block::load('views_block__article_view_block_1');
  //
  // // Assign variable to block type.
  // $variables['top_four_article'] = \Drupal::entityManager()
  //         ->getViewBuilder('block')
  //         ->view($top_four_article_block);
  //
  // // Get specific block type into variable.
  // $featured_article = \Drupal\block\Entity\Block::load('views_block__article_view_block_2');
  //
  // // Assign variable to block type.
  // $variables['featured_article'] = \Drupal::entityManager()
  //         ->getViewBuilder('block')
  //         ->view($featured_article);
  //
  //
  // Get specific block type into variable.
  // // Assign variable to block type.
  // $variables['logo'] = \Drupal::entityManager()
  //         ->getViewBuilder('block')
  //         ->view($logo);
  //
  //   // Get specific block type into variable.
  // $logo = \Drupal\block\Entity\Block::load('stickyiconsterms');
  //
  // Assign variable to block type.
}

function redactive_base_preprocess_region(&$variables){
  $theme_debug_val = theme_get_setting('debug_mode_layout')[0];
  $hide_block = theme_get_setting('hide_blocks')[0];
  $variables['debug_theme'] = $theme_debug_val;
  $variables['hide_block'] =  $hide_block;
}

function redactive_base_preprocess_block(&$variables){
  $theme_debug_val = theme_get_setting('debug_mode_layout')[0];
  $variables['debug_theme'] = $theme_debug_val;
}

function redactive_base_preprocess_node(&$variables){
  kint($variables);
  $theme_debug_val = theme_get_setting('debug_mode_layout')[0];
  $variables['debug_theme'] = $theme_debug_val;
}

function redactive_base_preprocess_field(&$variables){
  $theme_debug_val = theme_get_setting('debug_mode_layout')[0];
  $variables['debug_theme'] = $theme_debug_val;
}

function redactive_base_preprocess_views_view(&$variables){
  $theme_debug_val = theme_get_setting('debug_mode_layout')[0];
  $variables['debug_theme'] = $theme_debug_val;
}

function redactive_base_preprocess_menu(&$variables){
  $theme_debug_val = theme_get_setting('debug_mode_layout')[0];
  $variables['debug_theme'] = $theme_debug_val;
}



/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function redactive_base_theme_suggestions_html_alter(array &$suggestions, array $variables) {
  // Add custom template file with this
  // $suggestions[] = 'node__' . $node->getType();

  return $suggestions;
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function redactive_base_theme_suggestions_page_alter(array &$suggestions, array $variables) {

  $current_uri = \Drupal::request()->getRequestUri();

  if( $current_uri == "/" ){
    $suggestions[] = "page__front";
  }

  if ($node = \Drupal::routeMatch()->getParameter('node')) {
    $currentNode = \Drupal::routeMatch()->getParameter('node')->id();
    $node_storage = \Drupal::entityManager()->getStorage('node');
    $suggestions[] = 'node__' . $node->getType();

    // kint($currentNode);
    kint($node_storage->load($currentNode));
  }

  // $suggestions[] = "page__front";
  kint($variables);
  kint($suggestions);
  return $suggestions;
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function redactive_base_theme_suggestions_node_alter(array &$suggestions, array $variables) {
  if ($node = \Drupal::routeMatch()->getParameter('node')) {
    $suggestions[] = 'node__' . $node->getType();
  }
  $suggestions[] = 'node__' . $node->getType();
  // kint($variables);
  kint($suggestions);
  return $suggestions;
}

function redactive_base_theme_menu_main_alter(array &$suggestions, array $variables) {
  return $suggestions;
}


function redactive_base_theme_suggestions_region_alter(array &$suggestions, array $variables) {
  return $suggestions;
}

function redactive_base_theme_suggestions_block_alter(array &$suggestions, array $variables) {
  return $suggestions;
}

function redactive_base_theme_suggestions_taxonomy_term_alter(array &$suggestions, array $variables) {
  return $suggestions;
}

function redactive_base_theme_suggestions_views_view_alter(array &$suggestions, array $variables) {
  return $suggestions;
}

function redactive_base_theme_suggestions_search_result_alter(array &$suggestions, array $variables) {
  return $suggestions;
}

function redactive_base_theme_suggestions_field_alter(array &$suggestions, array $variables) {
  // Add custom template file with this
  // $suggestions[] = 'node__' . $node->getType();

  // kint("shshshs");
  // kint( $variables );

  // if( $variables['element']['#field_name'] == 'field_body'  || $variables['element']['#field_name'] == 'body' ){
  //    // kint( $variables );
  //    $suggestions[] = 'field__paragraphs' ;
  // }

  return $suggestions;
}

function redactive_base_form_alter(&$form, \Drupal\Core\Form\FormStateInterface $form_state, $form_id){
  kint("hhh");
  var_dump("gdgf");
}
