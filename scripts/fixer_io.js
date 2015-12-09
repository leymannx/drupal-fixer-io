(function($) {
  Drupal.behaviors.fixerIO = {
    attach: function (context, settings) {

      $('#fixer-io-switcher').change(function() {
        this.submit();
      });

    }
  };
})(jQuery);
