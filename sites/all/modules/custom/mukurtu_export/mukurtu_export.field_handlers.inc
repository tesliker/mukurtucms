<?php

// Stock Mukurtu Export Field Handlers
function mukurtu_export_mukurtu_export_field_handlers() {
    return array(
        'image' => array(
            '#module' => 'mukurtu_export',
            '#file' => drupal_get_path('module', 'mukurtu_export') . DIRECTORY_SEPARATOR . 'mukurtu_export.field_handlers.inc',
            '#callback' => 'mukurtu_export_field_handler_image'
        ),
        'taxonomy_term_reference' => array(
            '#module' => 'mukurtu_export',
            '#file' => drupal_get_path('module', 'mukurtu_export') . DIRECTORY_SEPARATOR . 'mukurtu_export.field_handlers.inc',
            '#callback' => 'mukurtu_export_field_handler_taxonomy_term_reference'
        ),
        'atom_reference' => array(
            '#module' => 'mukurtu_export',
            '#file' => drupal_get_path('module', 'mukurtu_export') . DIRECTORY_SEPARATOR . 'mukurtu_export.field_handlers.inc',
            '#callback' => 'mukurtu_export_field_handler_atom_reference'
        ),
        'node_reference' => array(
            '#module' => 'mukurtu_export',
            '#file' => drupal_get_path('module', 'mukurtu_export') . DIRECTORY_SEPARATOR . 'mukurtu_export.field_handlers.inc',
            '#callback' => 'mukurtu_export_field_handler_node_reference'
        ),
        'entityreference' => array(
            '#module' => 'mukurtu_export',
            '#file' => drupal_get_path('module', 'mukurtu_export') . DIRECTORY_SEPARATOR . 'mukurtu_export.field_handlers.inc',
            '#callback' => 'mukurtu_export_field_handler_entity_reference'
        ),
        'partial_date_range' => array(
            '#module' => 'mukurtu_export',
            '#file' => drupal_get_path('module', 'mukurtu_export') . DIRECTORY_SEPARATOR . 'mukurtu_export.field_handlers.inc',
            '#callback' => 'mukurtu_export_field_handler_partial_date_range'
        ),
        'scald_thumbnail' => array(
            '#module' => 'mukurtu_export',
            '#file' => drupal_get_path('module', 'mukurtu_export') . DIRECTORY_SEPARATOR . 'mukurtu_export.field_handlers.inc',
            '#callback' => 'mukurtu_export_field_handler_scald_thumbnail'
        ),
    );
}

// Handle Taxonomy Term References
function mukurtu_export_field_handler_taxonomy_term_reference($value, $field_info, $options = array()) {
    $referenced_entities = array();
    $files = array();

    if(isset($value['tid'])) {
        $term = taxonomy_term_load($value['tid']);
        if(isset($term->name)) {
            // Specific check for Mukurtu Taxonomy Records
            // Later we may want to fully run through all taxonomy fields, but this is good enough for now
            if(isset($term->field_mukurtu_records[LANGUAGE_NONE])) {
                foreach($term->field_mukurtu_records[LANGUAGE_NONE] as $record) {
                    $referenced_entities['node'][$record['target_id']] = $record['target_id'];
                }
            }
            return array($term->name, $referenced_entities, $files);
        }
    }
    return array(NULL, $referenced_entities, $files);
}

// Handle Images files (not Scald Atoms)
function mukurtu_export_field_handler_image($value, $field_info, $options = array()) {
    $referenced_entities = array();
    $binary_files = array();

    $saved_file = _mukurtu_export_save_file($value);
    $return_value = MUKURTU_EXPORT_IMPORT_DIR . DIRECTORY_SEPARATOR . $saved_file[$value['fid']]['filename'];

    return array($return_value, $referenced_entities, $saved_file);
}

// Handle entityreference fields
function mukurtu_export_field_handler_entity_reference($value, $field_info, $options = array()) {
    $referenced_entities = array();
    $files = array();

    if(isset($value['target_id'])) {
        if(isset($field_info['settings']['target_type'])) {
            $referenced_entities[$field_info['settings']['target_type']][$value['target_id']] = $value['target_id'];
        }

        if(isset($options['id_format']) && ($options['id_format'] == 'guid')) {
            $guid = _mukurtu_export_entity_get_guid($field_info['settings']['target_type'], $value['target_id']);
            return array($guid, $referenced_entities, $files);
        }
        return array($value['target_id'], $referenced_entities, $files);
    }
    return array(NULL, $referenced_entities, $files);
}

function mukurtu_export_field_handler_node_reference($value, $field_info, $options = array()) {
    $referenced_entities = array();
    $files = array();

    if(isset($value['nid'])) {
        $referenced_entities['node'][$value['nid']] = $value['nid'];
        if(isset($options['id_format']) && ($options['id_format'] == 'guid')) {
            $guid = _mukurtu_export_entity_get_guid('node', $value['nid']);
            return array($guid, $referenced_entities, $files);
        }
        return array($value['nid'], $referenced_entities, $files);
    }
    return array(NULL, $referenced_entities, $files);
}

function mukurtu_export_field_handler_atom_reference($value, $field_info, $options = array()) {
    $referenced_entities = array();
    $files = array();

    if(isset($value['sid'])) {
        $referenced_entities['scald_atom'][$value['sid']] = $value['sid'];

        if(isset($options['id_format']) && ($options['id_format'] == 'guid')) {
            $guid = _mukurtu_export_entity_get_guid('scald_atom', $value['sid']);
            return array($guid, $referenced_entities, $files);
        }

        return array($value['sid'], $referenced_entities, $files);
    }
    return array(NULL, $referenced_entities, $files);
}

function mukurtu_export_field_handler_partial_date_range($value, $field_info, $options = array()) {
    $referenced_entities = array();
    $files = array();

    if(isset($value['timestamp'])) {
        return array($value['timestamp'], $referenced_entities, $files);
    }
    return array(NULL, $referenced_entities, $files);
}

function mukurtu_export_field_handler_scald_thumbnail($value, $field_info, $options = array()) {
    $referenced_entities = array();
    $files = array();

    return array(NULL, $referenced_entities, $files);
}

function _mukurtu_export_save_file($file) {
    $uri_scheme = file_uri_scheme($file['uri']);
    $localname = implode(DIRECTORY_SEPARATOR, array('files', $uri_scheme, $file['type'], $file['fid'], $file['filename']));
    return array($file['fid'] => array('uri' => $file['uri'], 'filename' => $localname));
}