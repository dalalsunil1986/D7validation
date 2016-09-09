<?php

/**
 * @file
 * This is the Form Validation Tutorial.
 * Demonstrate how many ways we can validate the form instance.
 */

/*
 * Field validation example 1
 */
function article_val_tutorial_1($form, &$form_state){
    $form['first'] = array(
        '#type' => 'textfield',
        '#title' => t('First name'),
        '#description' => "validate form field,instead of checking full form.",
        '#size' => 20,
        '#maxlength' => 20,
        '#element_validate' => array('article_rule_field_validate'),
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'Submit',
    );
    return $form;
}

/*
 * Sample 1: A form with a validate handler.
 */
function article_rule_field_validate($element, $form_state){
  if (is_numeric($form_state['values']['first'])) {
      form_error($element, t('first name should not be numeric.'));
  }
}

/*
 * Field validation sample 2 with pre-defined validatior.
 */
function article_val_tutorial_2($form, &$form_state){
    $form['last'] = array(
        '#type' => 'textfield',
        '#title' => t('last name'),
        '#description' => "field accept only numbers, alpha character should throw error.",
        '#size' => 20,
        '#maxlength' => 20,
        '#element_validate' => array('element_validate_number'),
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'Submit',
    );
    return $form;
}

/*
 * Field validation sample 3 form_id_form_validate
 */
function article_val_tutorial_3($form, &$form_state){
    $form['username'] = array(
        '#type' => 'textfield',
        '#title' => t('username'),
        '#description' => "validating using _form_validate API.",
        '#size' => 20,
        '#maxlength' => 20,
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'Submit',
    );
    return $form;
}

/*
 * Sample 3: A form with a validate handler.
 */
function article_val_tutorial_3_validate($element, $form_state){
    if (empty($form_state['values']['username'])) {
        form_error($element, t('username should not be empty.'));
    }
}

?>