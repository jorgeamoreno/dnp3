﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using DNP3.Interface;

namespace DNP3TestHarness
{
    public partial class TestHarnessForm : Form
    {
        class LogAdapter : ILogHandler
        {
            public LogAdapter(Action<LogEntry> action)
            {
                this.action = action;
            }

            void ILogHandler.Log(LogEntry entry)
            {
                action(entry);
            }

            private Action<LogEntry> action;
        }

        public TestHarnessForm(IDNP3Manager manager)
        {
            this.manager = manager;

            InitializeComponent();

            manager.AddLogHandler(new LogAdapter(OnLogEntry));
            manager.AddLogHandler(PrintingLogAdapter.Instance);
          
            var client = manager.AddTCPClient("client", LogLevels.NORMAL, TimeSpan.FromSeconds(1), TimeSpan.FromMinutes(1), "127.0.0.1", 20000);
            var master = client.AddMaster("master", PrintingSOEHandler.Instance, new MasterStackConfig());
            master.Enable();
        }

        private void OnLogEntry(LogEntry entry)
        {            
            this.BeginInvoke(new Action(() => this.listBoxLog.Items.Add(GetLogString(entry))));
        }

        private string GetLogString(LogEntry entry)
        {
            return entry.time.ToLongTimeString() + " - " + entry.loggerName + " - " + entry.message;
        }

        private IDNP3Manager manager;
    }
}