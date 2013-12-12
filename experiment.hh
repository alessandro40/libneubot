//
// LibNeubot interface - Public domain.
// WARNING: Autogenerated file - do not edit!
//

namespace Neubot {

  class Pollable {
      struct ::NeubotPollable *_context;

    public:
      operator struct ::NeubotPollable *() {
        return (this->_context);
      }

      virtual void handle_read(void) {
      };

      static void handle_read_callback(void *opaque) {
        Pollable *self;
        self = (Pollable *) opaque;
        self->handle_read();
      };

      virtual void handle_write(void) {
      };

      static void handle_write_callback(void *opaque) {
        Pollable *self;
        self = (Pollable *) opaque;
        self->handle_write();
      };

      virtual void handle_free(void) {
      };

      static void handle_free_callback(void *opaque) {
        Pollable *self;
        self = (Pollable *) opaque;
        self->handle_free();
      };

      ~Pollable(void) {
        ::NeubotPollable_free(this->_context);
      };

      struct ::NeubotPoller * poller(void) {
        return (::NeubotPollable_poller(this->_context));
      };

      int attach(long long filenum) {
        return (::NeubotPollable_attach(this->_context, filenum));
      };

      void detach(void) {
        ::NeubotPollable_detach(this->_context);
      };

      long long fileno(void) {
        return (::NeubotPollable_fileno(this->_context));
      };

      int set_readable(void) {
        return (::NeubotPollable_set_readable(this->_context));
      };

      int unset_readable(void) {
        return (::NeubotPollable_unset_readable(this->_context));
      };

      int set_writable(void) {
        return (::NeubotPollable_set_writable(this->_context));
      };

      int unset_writable(void) {
        return (::NeubotPollable_unset_writable(this->_context));
      };

      void set_timeout(double delta) {
        ::NeubotPollable_set_timeout(this->_context, delta);
      };

      void clear_timeout(void) {
        ::NeubotPollable_clear_timeout(this->_context);
      };

      Pollable(struct ::NeubotPoller * poller) {
        this->_context = ::NeubotPollable_construct(poller);
        if (this->_context == NULL)
          throw new std::bad_alloc();
        ::NeubotPollable_set_handle_read_slot(this->_context, this->handle_read_callback, this);
        ::NeubotPollable_set_handle_write_slot(this->_context, this->handle_write_callback, this);
        ::NeubotPollable_set_handle_free_slot(this->_context, this->handle_free_callback, this);
      };

  };

  class Poller {
      struct ::NeubotPoller *_context;

    public:
      operator struct ::NeubotPoller *() {
        return (this->_context);
      }

      ~Poller(void) {
        ::NeubotPoller_free(this->_context);
      };

      void break_loop(void) {
        ::NeubotPoller_break_loop(this->_context);
      };

      Poller() {
        this->_context = ::NeubotPoller_construct();
        if (this->_context == NULL)
          throw new std::bad_alloc();
      };

  };

};
