<?php
/**
 * @file
 * ma_importexport_dc.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function ma_importexport_dc_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'digital_heritage_dc';
  $feeds_importer->config = array(
    'name' => 'Import Digital Heritage Dublin Core XML',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'xml',
        'delete_uploaded_file' => 1,
        'direct' => 0,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsExXml',
      'config' => array(
        'context' => array(
          'value' => 'rdf:RDF/rdf:Description',
        ),
        'sources' => array(
          'guid' => array(
            'name' => 'guid',
            'value' => 'guid',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '0',
          ),
          'dc_title' => array(
            'name' => 'dc:title',
            'value' => 'dc:title',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '1',
          ),
          'dc_creator' => array(
            'name' => 'dc:creator',
            'value' => 'dc:creator',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '2',
          ),
          'dc_contributor' => array(
            'name' => 'dc:contributor',
            'value' => 'dc:contributor',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '3',
          ),
          'dc_date' => array(
            'name' => 'dc:date',
            'value' => 'dc:date',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '4',
          ),
          'dc_description' => array(
            'name' => 'dc:description',
            'value' => 'dc:description',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '5',
          ),
          'dc_publisher' => array(
            'name' => 'dc:publisher',
            'value' => 'dc:publisher',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '6',
          ),
          'dc_rights' => array(
            'name' => 'dc:rights',
            'value' => 'dc:rights',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '7',
          ),
          'dc_format' => array(
            'name' => 'dc:format',
            'value' => 'dc:format',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '8',
          ),
          'dc_type' => array(
            'name' => 'dc:type',
            'value' => 'dc:type',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '9',
          ),
          'dc_identifier' => array(
            'name' => 'dc:identifier',
            'value' => 'dc:identifier',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '10',
          ),
          'dc_language' => array(
            'name' => 'dc:language',
            'value' => 'dc:language',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '11',
          ),
          'dc_source' => array(
            'name' => 'dc:source',
            'value' => 'dc:source',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '12',
          ),
          'dc_subject' => array(
            'name' => 'dc:subject',
            'value' => 'dc:subject',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '13',
          ),
          'dc_coverage' => array(
            'name' => 'dc:coverage',
            'value' => 'dc:coverage',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '14',
          ),
          'dc_hasformat' => array(
            'name' => 'dc:hasformat',
            'value' => 'dc:hasformat',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '15',
          ),
          'dc_relation' => array(
            'name' => 'dc:relation',
            'value' => 'dc:relation',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '16',
          ),
        ),
        'display_errors' => 0,
        'debug_mode' => 0,
        'source_encoding' => array(
          0 => 'auto',
        ),
        'use_tidy' => FALSE,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'dc_title',
            'target' => 'title',
            'unique' => 0,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'dc_creator',
            'target' => 'field_creator',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          3 => array(
            'source' => 'dc_contributor',
            'target' => 'field_contributor',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          4 => array(
            'source' => 'dc_date',
            'target' => 'field_date',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'dc_description',
            'target' => 'field_description',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'dc_publisher',
            'target' => 'field_publisher',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          7 => array(
            'source' => 'dc_rights',
            'target' => 'field_rights',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'dc_format',
            'target' => 'field_format',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          9 => array(
            'source' => 'dc_type',
            'target' => 'field_dh_type',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          10 => array(
            'source' => 'dc_identifier',
            'target' => 'field_identifier',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'dc_language',
            'target' => 'field_language',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          12 => array(
            'source' => 'dc_source',
            'target' => 'field_source',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'dc_subject',
            'target' => 'field_subject',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          14 => array(
            'source' => 'dc_coverage',
            'target' => 'field_coverage_description',
            'unique' => FALSE,
            'language' => 'und',
          ),
          15 => array(
            'source' => 'dc_hasformat',
            'target' => 'field_media_asset',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'digital_heritage',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['digital_heritage_dc'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'digital_heritage_mods';
  $feeds_importer->config = array(
    'name' => 'Import Digital Heritage MODS XML',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'xml',
        'delete_uploaded_file' => 1,
        'direct' => 0,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
          'private' => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsExXml',
      'config' => array(
        'context' => array(
          'value' => 'modsCollection/mods',
        ),
        'sources' => array(
          'guid' => array(
            'name' => 'guid',
            'value' => 'guid',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '0',
          ),
          'dc_title' => array(
            'name' => 'dc:title',
            'value' => 'titleInfo/title',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '1',
          ),
          'dc_creator' => array(
            'name' => 'dc:creator',
            'value' => 'name',
            'raw' => 1,
            'inner' => 0,
            'debug' => 0,
            'weight' => '2',
          ),
          'dc_contributor' => array(
            'name' => 'dc:contributor',
            'value' => 'name',
            'raw' => 1,
            'inner' => 0,
            'debug' => 0,
            'weight' => '3',
          ),
          'dc_date' => array(
            'name' => 'dc:date',
            'value' => 'originInfo/dateCreated',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '4',
          ),
          'dc_description' => array(
            'name' => 'dc:description',
            'value' => 'note',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '5',
          ),
          'dc_publisher' => array(
            'name' => 'dc:publisher',
            'value' => 'originInfo/publisher',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '6',
          ),
          'dc_rights' => array(
            'name' => 'dc:rights',
            'value' => 'accessCondition',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '7',
          ),
          'dc_format' => array(
            'name' => 'dc:format',
            'value' => 'physicalDescription/extent',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '8',
          ),
          'dc_type' => array(
            'name' => 'dc:type',
            'value' => 'typeOfResource',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '9',
          ),
          'dc_identifier' => array(
            'name' => 'dc:identifier',
            'value' => 'identifier',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '10',
          ),
          'dc_language' => array(
            'name' => 'dc:language',
            'value' => 'language/languageTerm',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '11',
          ),
          'dc_source' => array(
            'name' => 'dc:source',
            'value' => 'relatedItem',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '12',
          ),
          'dc_subject' => array(
            'name' => 'dc:subject',
            'value' => 'classification',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '13',
          ),
          'dc_coverage' => array(
            'name' => 'dc:coverage',
            'value' => 'originInfo/place/placeTerm',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '14',
          ),
          'dc_hasformat' => array(
            'name' => 'dc:hasformat',
            'value' => 'location/url',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '15',
          ),
          'dc_relation' => array(
            'name' => 'dc:relation',
            'value' => 'relatedItem',
            'raw' => 0,
            'inner' => 0,
            'debug' => 0,
            'weight' => '16',
          ),
        ),
        'display_errors' => 1,
        'debug_mode' => 1,
        'source_encoding' => array(
          0 => 'auto',
        ),
        'use_tidy' => FALSE,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'dc_title',
            'target' => 'title',
            'unique' => 0,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'dc_creator',
            'target' => 'field_creator',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          3 => array(
            'source' => 'dc_contributor',
            'target' => 'field_contributor',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          4 => array(
            'source' => 'dc_date',
            'target' => 'field_date',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'dc_description',
            'target' => 'field_description',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'dc_publisher',
            'target' => 'field_publisher',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          7 => array(
            'source' => 'dc_rights',
            'target' => 'field_rights',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'dc_format',
            'target' => 'field_format',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          9 => array(
            'source' => 'dc_type',
            'target' => 'field_dh_type',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          10 => array(
            'source' => 'dc_identifier',
            'target' => 'field_identifier',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'dc_language',
            'target' => 'field_language',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          12 => array(
            'source' => 'dc_source',
            'target' => 'field_source',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'dc_subject',
            'target' => 'field_subject',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          14 => array(
            'source' => 'dc_coverage',
            'target' => 'field_coverage_description',
            'unique' => FALSE,
            'language' => 'und',
          ),
          15 => array(
            'source' => 'dc_hasformat',
            'target' => 'field_media_asset',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'digital_heritage',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['digital_heritage_mods'] = $feeds_importer;

  return $export;
}
