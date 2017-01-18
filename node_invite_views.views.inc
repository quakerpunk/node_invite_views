<?php
/**
 * Implementation of hook_views_handlers().
 */
function node_invite_views_views_handlers() {
  return array(
    'handlers' => array(
      'node_invite_invitee_list_handler_field' => array(
        'parent' => 'views_handler_field_numeric',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_data().
 */
function node_invite_views_views_data() {
  $data = array();
  $data['node_invites']['table']['group'] = t('Node Invite');
  $data['node_invites']['table']['base'] = array(
    'field' => 'iid',
    'title' => t('Node Invites'),
    'help' => t('This table contains the invites for the site.'),
    'weight' => -10,
  );
  
  //Join
  $data['node_invites']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid_inviter',
      'extra' => array(
        array(
          'field' => 'uid_invitee',
          'value' => 'users.uid',
          'operator' => '=',
          'numeric' => true,
        ),
      ),
    ),
  );
  
  //Field descriptions
  $data['node_invites']['iid'] = array(
    'title' => t('Invite ID'),
    'help' => t('The id of an invite. Primary key.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => true,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['node_invites']['nid'] = array(
    'title' => t('Node ID'),
    'help' => t('The node that this invite relates to.'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Invites on this node.'),
      'title' => t('Invites for this node.'),
      'help' => t('Defines a relationship between an invite and its node.'),
    ),
  );
  
  $data['node_invites']['uid_inviter'] = array(
    'title' => t('Inviter User ID'),
    'help' => t('The user ID of the issuer of the invite.'),
    'relationship' => array(
      'base' => 'users',
      'base field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('Invites this user has issued.'),
      'title' => t('Invites by this user.'),
      'help' => t('Defines a relationship between an invite and its inviter.'),
    ),
  );
  
  $data['node_invites']['inviter_customer_name'] = array(
    'title' => t('Inviter\'s Custom Name'), 
    'help' => t('The name of the inviter. This can be customized.'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE, // This is use by the table display plugin.
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['node_invites']['inviter_customer_email'] = array(
    'title' => t('Inviter\'s Custom Email'), 
    'help' => t('The email address of the inviter. This can be customized.'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE, // This is use by the table display plugin.
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['node_invites']['email_invitee'] = array(
    'title' => t('Invitee\'s Email'), 
    'help' => t('The email address of the invitee.'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE, // This is use by the table display plugin.
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['node_invites']['name_invitee'] = array(
    'title' => t('Invitee\'s Name'), 
    'help' => t('The name of the invitee. May be the same as the invitee\'s email address.'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE, // This is use by the table display plugin.
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['node_invites']['uid_invitee'] = array(
    'title' => t('Invitee User ID'),
    'help' => t('The user ID of the issuer of the invitee.'),
    'relationship' => array(
      'base' => 'users',
      'base field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('Invites this user has received.'),
      'title' => t('Invites received by this user.'),
      'help' => t('Defines a relationship between an invite and its invitee.'),
    ),
  );
  
  $data['node_invites']['status'] = array(
    'title' => t('The invite\'s status'), 
    'help' => t('The status of the invitee. Can be Yes, No, or NEW'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE, // This is use by the table display plugin.
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['node_invites']['status'] = array(
    'title' => t('The invite\'s status'), 
    'help' => t('The status of the invitee. Can be Yes, No, or NEW'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE, // This is use by the table display plugin.
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['node_invites']['sent'] = array(
    'title' => t('Sent'),
    'help' => t('The time the invite was sent.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => true,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['node_invites']['acted_upon'] = array(
    'title' => t('Acted Upon'),
    'help' => t('The time the invite was responded to.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => true,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['node_invites']['notes_invitee'] = array(
    'title' => t('The invitee\'s notes'), 
    'help' => t('Notes left by the invitee'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE, // This is use by the table display plugin.
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['node_invites']['notes_inviter'] = array(
    'title' => t('The invitee\'s notes'), 
    'help' => t('Notes left by the inviter'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE, // This is use by the table display plugin.
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['node_invites']['hash'] = array(
    'title' => t('Hash'), 
    'help' => t('A hash generated by the invitee\'s email and time it was sent.'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE, // This is use by the table display plugin.
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  $data['node_invites']['personal_message'] = array(
    'title' => t('Personal message'), 
    'help' => t('A personal message sent with each invite.'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE, // This is use by the table display plugin.
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  return $data;
}
